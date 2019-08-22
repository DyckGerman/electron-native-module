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

  auto cb = CMS::VideoFrameCallbackHolder::unwrap(info.GetIsolate(), info[0]->ToObject());
  if(cb == NULL) {
    Nan::ThrowTypeError("11111 cannot unwrap CustomMediaStream::VideoFrameCallback");
    return;
  }
  

  
  int i = 1;
  // for (auto i = 0; i < 10000; i++) {
    auto frame = cb->allocate({0}, CMS::Format {100, 100});

    // void * dataY = frame->data(CMS::Plane::Y);
    // memset(dataY, 41, 1000);
    void * dataU = frame->data(CMS::Plane::U);
    memset(dataU, 161, 5000);
    void * dataV = frame->data(CMS::Plane::V);
    memset(dataV, 169, 5000);

    cb->queue({0}, std::move(frame));
  // }

    auto frame = cb->allocate({0}, CMS::Format {100, 100});
  // for (auto i = 0; i < 10000; i++) {
  int i = 1;

  
}

NAN_MODULE_INIT(custom_capturer_init) {
  Nan::Set(target, Nan::New("startCapture").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(startCapture)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE, custom_capturer_init);
