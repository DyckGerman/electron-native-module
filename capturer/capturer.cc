#include <utility>
#include <iostream>

#include <nan.h>
#include <custom_media_stream.h>

namespace CMS = CustomMediaStream;

//v8::Global<v8::Object> control_handle;
//CustomMediaStream::VideoFrameCallback* callback;

std::shared_ptr<CMS::VideoFrameCallbackHolder> callback;

NAN_METHOD(startCapture) {
  std::cerr << "addCaptureStreamToMediaStream" << info.Length() << std::endl;

  if(info.Length() < 1) {
    Nan::ThrowTypeError("not enough arguments");
    return;
  }

  auto cb = CMS::VideoFrameCallbackHolder::unwrap(info.GetIsolate(), info[0]->ToObject(info.GetIsolate()));

  if(!cb) {
    Nan::ThrowTypeError("cannot unwrap CustomMediaStream::VideoFrameCallback");
    return;
  }

  callback = cb;
  
}

NAN_MODULE_INIT(custom_capturer_init) {
  Nan::Set(target, Nan::New("startCapture").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(startCapture)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE, custom_capturer_init);
