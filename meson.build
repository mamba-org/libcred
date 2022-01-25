project(
    'credhelper', 'c',
    version : '0.1.0',
    meson_version : '>=0.53.0',
    default_options : []
)

if host_machine.system() == 'darwin'
    subdir('src/osx')
endif

if host_machine.system() == 'linux'
    subdir('src/linux')
endif