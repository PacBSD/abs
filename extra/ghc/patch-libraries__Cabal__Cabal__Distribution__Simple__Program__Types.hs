--- ./libraries/Cabal/Cabal/Distribution/Simple/Program/Types.hs.orig	2012-11-23 17:07:58.000000000 +0100
+++ ./libraries/Cabal/Cabal/Distribution/Simple/Program/Types.hs	2012-11-23 19:19:04.000000000 +0100
@@ -18,6 +18,7 @@
     -- * Program and functions for constructing them
     Program(..),
     simpleProgram,
+    simpleProgramFromEnvironment,
 
     -- * Configured program and related functions
     ConfiguredProgram(..),
@@ -28,6 +29,8 @@
 import Distribution.Simple.Program.Find
          ( ProgramSearchPath, ProgramSearchPathEntry(..)
          , findProgramOnSearchPath )
+import Distribution.Simple.Utils
+         ( getProgramFromEnvironment )
 import Distribution.Version
          ( Version )
 import Distribution.Verbosity
@@ -116,6 +117,18 @@
     programPostConf     = \_ _ -> return []
   }
 
+-- | Make a simple named program from an environment variable.
+--
+-- > simpleProgramFromEnvironment "foo" "FOO"
+--
+simpleProgramFromEnvironment :: String -> String -> Program
+simpleProgramFromEnvironment name var = Program {
+    programName         = name,
+    programFindLocation = \v _ -> getProgramFromEnvironment v name var,
+    programFindVersion  = \_ _ -> return Nothing,
+    programPostConf     = \_ p -> return p
+  }
+
 -- | Make a simple 'ConfiguredProgram'.
 --
 -- > simpleConfiguredProgram "foo" (FoundOnSystem path)
