--- examples/ThirdPartyLibs/Gwen/Macros.h.orig	2015-09-27 16:41:08.751064518 +0100
+++ examples/ThirdPartyLibs/Gwen/Macros.h	2015-09-27 16:41:39.299153485 +0100
@@ -38,7 +38,7 @@
 	#define GwenUtil_OutputDebugWideString( lpOutputString ) //wprintf( lpOutputString  )
 	#define GwenUtil_WideStringToFloat( _Str ) wcstof(_Str, NULL)
 
-#elif defined(__linux__)
+#elif defined(__linux__) || (__FreeBSD__)
 
 	#define GwenUtil_VSNPrintFSafe( _DstBuf, _DstSize, _MaxCount, _Format, _ArgList ) vsnprintf( _DstBuf, _DstSize, _Format, _ArgList )
 	#define GwenUtil_VSWPrintFSafe( _DstBuf, _SizeInWords, _Format, _ArgList ) vswprintf( _DstBuf, _SizeInWords, _Format, _ArgList )
