{
  "targets": [
    {
      "target_name": "capturer",
      "sources": [ "capturer.cc" ],
      "include_dirs": [
          "/Users/dyckgerman/projects/electron-gn/src/out/Debug/gen/node_headers",
          "/Users/dyckgerman/projects/electron-gn/src/third_party/nan",
          "/Users/dyckgerman/projects/electron-gn/src/electron/shell/common/api",
      ],
      "configurations": {
        "Debug": {
            "conditions": [
                ["OS=='mac'", {
                    "xcode_settings": {
                        "LD_RUNPATH_SEARCH_PATHS": [
                            "../captbuild/Debug/",  # when installed as a dependency
                            "./build/Debug/",
                            "@loader_path"                                    # near plug-in 
                        ],
                    }
                }]
            ]
        },
        "Release": {
            "conditions": [
                ["OS=='mac'", {
                    "xcode_settings": {
                        "LD_RUNPATH_SEARCH_PATHS": [
                            "../capturer/build/Release/",
                            "./build/Release/",
                            "@loader_path"
                        ],
                    }
                }]
            ]
        }
      },
      "conditions": [
                ["OS=='mac'", {
                    'defines': [
                        #'CURL_STATICLIB',
                        'ENABLE_ESS_ASSERTIONS',
                    ],
                    'xcode_settings': {
                        'BUILD_DIR': 'build',
                        'MACOSX_DEPLOYMENT_TARGET': '10.13',
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                        'GCC_ENABLE_CPP_RTTI':'YES',
                        'CLANG_ENABLE_OBJC_ARC': 'YES',
                    },
                    #'libraries': [
                    #    'libcurl.a',
                    #    'libcurlcpp.a',
                    #],
                }]
            ]
    }
  ]
}
