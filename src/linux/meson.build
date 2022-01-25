so_version = '1'

lib_sources = ['secretservice_linux.c']

libsecret_dep = dependency('libsecret-1')
glib_dep = dependency('glib-2.0')

credhelperlib = library('credhelper',
                lib_sources,
                c_args: [],
                include_directories: '.',
                dependencies: [libsecret_dep, glib_dep],
                install: true,
                version: meson.project_version(),
                soversion: so_version
            )
