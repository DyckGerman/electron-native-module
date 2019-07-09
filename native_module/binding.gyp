{
  "targets": [
    {
      "target_name": "capturer",
      "sources": [ "capturer.cc" ],
      "include_dirs": [
          "<!(node -e \"require('nan')\")",
          "/home/octopus/projects/electron-gn/src"
      ]
    }
  ]
}
