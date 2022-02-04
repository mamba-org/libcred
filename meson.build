project(
    'libcred', 'cpp',
    version : '0.1.0',
    meson_version : '>=0.53.0',
    default_options : []
)

so_version = '1'

if host_machine.system() == 'darwin'
    impl_sources = ['src/libcred_macos.cpp']
    apple_deps = dependency('appleframeworks', modules : ['CoreFoundation', 'Security'])

    credhelperlib = library('cred',
                    impl_sources,
                    c_args: [],
                    include_directories: 'include',
                    dependencies: [apple_deps],
                    install: true,
                    version: meson.project_version(),
                    soversion: so_version
                )
endif

if host_machine.system() == 'linux'

    impl_sources = ['src/libcred_linux.cpp']

    libsecret_dep = dependency('libsecret-1')
    glib_dep = dependency('glib-2.0')

    credhelperlib = library('cred',
                    impl_sources,
                    c_args: [],
                    include_directories: 'include',
                    dependencies: [libsecret_dep, glib_dep],
                    install: true,
                    version: meson.project_version(),
                    soversion: so_version
                )
endif

if host_machine.system() == 'windows'
    impl_sources = ['src/libcred_win.cpp']

    credhelperlib = shared_library('cred',
                    impl_sources,
                    cpp_args: ['-DLIBCRED_EXPORTS=1'],
                    include_directories: 'include',
                    dependencies: [],
                    install: true,
                    version: meson.project_version(),
                    soversion: so_version
                )
endif

executable('ex1', ['example/ex1.cpp'], link_with: credhelperlib, include_directories: ['include'])
