#!/bin/sh

db_small_url='%%SMALL_URL%%'
db_full_url='%%FULL_URL%%'
db_path='/var/db'
db_small_file='pkgdep.db.gz'
db_full_file='full.db.gz'

fetch -o "${db_path}/${db_small_file}" "${db_small_url}"
fetch -o "${db_path}/${db_full_file}" "${db_full_url}"
