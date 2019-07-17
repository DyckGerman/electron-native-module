#include <utility>
#include <iostream>

#include <nan.h>
#include <custom_media_stream.h>

namespace CMS = CustomMediaStream;
using FramePtr = std::unique_ptr<CMS::VideoFrame, CMS::detail::VideoFrameReleaser>;
//v8::Global<v8::Object> control_handle;
//CustomMediaStream::VideoFrameCallback* callback;

std::shared_ptr<CMS::VideoFrameCallbackHolder> callback;

NAN_METHOD(startCapture) {
  std::cerr << "addCaptureStreamToMediaStream" << info.Length() << std::endl;

  auto cb = CMS::VideoFrameCallbackHolder::unwrap(info.GetIsolate(), info.Data());
  if(cb == NULL) {
    Nan::ThrowTypeError("cannot unwrap CustomMediaStream::VideoFrameCallback");
    return;
  }

  auto frame = cb->allocate({0}, CMS::Format {600, 300});
  cb->queue({0}, std::move(frame));

  
}

NAN_MODULE_INIT(custom_capturer_init) {
  Nan::Set(target, Nan::New("startCapture").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(startCapture)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE, custom_capturer_init);
