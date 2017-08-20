/*
 * $FreeBSD: ports/devel/qmake/files/qconfig.cpp,v 1.4 2012/11/17 05:56:55 svnexp Exp $
 * Hand-crafted...
 * The default prefix (/ usr / local) is dynamicly replaced
 * at configure time.
 */
const char *qInstallPath()             { return "/usr"; }
const char *qInstallPathDocs()         { return "/usr/share/doc/qt"; }
const char *qInstallPathHeaders()      { return "/usr/include"; }
const char *qInstallPathLibs()         { return "/usr/lib"; }
const char *qInstallPathBins()         { return "/usr/bin"; }
const char *qInstallPathPlugins()      { return "/usr/plugins"; }
const char *qInstallPathData()         { return "/usr/share/qt"; }
const char *qInstallPathTranslations() { return "/usr/translations"; }
const char *qInstallPathSysconf()      { return "/etc"; }
