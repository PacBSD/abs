## PacBSD

These are the collections of PKGBUILDS tweaked for building packages with makepkg on FreeBSD systems.

## Why Not use ArchLinux PKGBUILDS

We normally do as a template, but to build on FreeBSD we need to patch. We also need to run autotool fixes and other 
tasks to successfully build. For that we modified makepkg and have our own PKGBUILDS.

# files folder

To get packages to build, we needed to patch them. Some programs have quite a sizable amount of patches and these polluted PKGBUILDS,
to solve this, we added a function to makepkg which applies all patches in the files directory"

# Other PKGBUILDS

The other PKGBUILDS have been moved to unstable branch, only the ones that have been packages and maintained are currently in master.
Of course the PKGBUILDS in unstable still build, an dalready been modified for our makepkg.
