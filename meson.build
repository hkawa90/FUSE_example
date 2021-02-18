project('cpputest', 'c', 'cpp')

c_compile_options = ['-g', '-Wall', '-DMAKE_SHARED']
#c_compile_options = ['-g', '-Wall', '-DUSE_LOW_LEVEL_API']

cc = meson.get_compiler('c')

#lib_fuse = cc.find_library('fuse', required: true)
lib_fuse = dependency('fuse')
lib_pthread = cc.find_library('pthread', required: true)



executable('inotify_test', 
                 ['inotify_test.cpp'])

appFS_slib = shared_library(
  'appFS',
  ['appFS.c'],
#  include_directories: includes,
  c_args: c_compile_options,
#  link_args: c_link_options,
  dependencies: [lib_fuse, lib_pthread],
  install: false,
)


appFS_lib = static_library(
  'appFS',
  ['appFS.c'],
#  include_directories: includes,
  c_args: c_compile_options,
#  link_args: c_link_options,
  dependencies: [lib_fuse, lib_pthread],
  install: false,
)


appFS_slib_dummy = shared_library(
  'appFS_dummy',
  ['appFS_dummy.c'],
  c_args: c_compile_options,
  install: false,
)

executable('appFS_sample1',
                 ['app.c'],
                 link_with: [appFS_lib],
                 c_args: c_compile_options)

executable('appFS_sample2',
                 ['app.c'],
                 link_with: [appFS_slib_dummy],
                 c_args: c_compile_options)
