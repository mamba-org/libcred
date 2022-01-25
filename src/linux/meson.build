so_version = '1'

lib_sources = ['secretservice_linux.c']

secret_deps = dependency('secret')

zcklib = library('credhelper',
                lib_sources,
                c_args: [],
                include_directories: '.',
                dependencies: secret_deps,
                install: true,
                version: meson.project_version(),
                soversion: so_version
            )
