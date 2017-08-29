From 03c91c76daf70ee227f38304c5e45a155f45073d Mon Sep 17 00:00:00 2001
From: Dan Winship <danw@gnome.org>
Date: Thu, 3 Aug 2017 09:56:43 -0400
Subject: Fix chunked decoding buffer overrun (CVE-2017-2885)

https://bugzilla.gnome.org/show_bug.cgi?id=785774
---
 libsoup/soup-filter-input-stream.c | 22 +++++++++++-----------
 1 file changed, 11 insertions(+), 11 deletions(-)

diff --git a/libsoup/soup-filter-input-stream.c b/libsoup/soup-filter-input-stream.c
index cde4d12..2c30bf9 100644
--- libsoup/soup-filter-input-stream.c
+++ libsoup/soup-filter-input-stream.c
@@ -198,7 +198,7 @@ soup_filter_input_stream_read_until (SoupFilterInputStream  *fstream,
 				     GCancellable           *cancellable,
 				     GError                **error)
 {
-	gssize nread;
+	gssize nread, read_length;
 	guint8 *p, *buf, *end;
 	gboolean eof = FALSE;
 	GError *my_error = NULL;
@@ -251,10 +251,11 @@ soup_filter_input_stream_read_until (SoupFilterInputStream  *fstream,
 	} else
 		buf = fstream->priv->buf->data;
 
-	/* Scan for the boundary */
-	end = buf + fstream->priv->buf->len;
-	if (!eof)
-		end -= boundary_length;
+	/* Scan for the boundary within the range we can possibly return. */
+	if (include_boundary)
+		end = buf + MIN (fstream->priv->buf->len, length) - boundary_length;
+	else
+		end = buf + MIN (fstream->priv->buf->len - boundary_length, length);
 	for (p = buf; p <= end; p++) {
 		if (*p == *(guint8*)boundary &&
 		    !memcmp (p, boundary, boundary_length)) {
@@ -268,10 +269,9 @@ soup_filter_input_stream_read_until (SoupFilterInputStream  *fstream,
 	if (!*got_boundary && fstream->priv->buf->len < length && !eof)
 		goto fill_buffer;
 
-	/* Return everything up to 'p' (which is either just after the boundary if
-	 * include_boundary is TRUE, just before the boundary if include_boundary is
-	 * FALSE, @boundary_len - 1 bytes before the end of the buffer, or end-of-
-	 * file).
-	 */
-	return read_from_buf (fstream, buffer, p - buf);
+	if (eof && !*got_boundary)
+		read_length = MIN (fstream->priv->buf->len, length);
+	else
+		read_length = p - buf;
+	return read_from_buf (fstream, buffer, read_length);
 }
-- 
cgit v0.12

