#include <utility>
#include <iostream>

#include <nan.h>
#include <custom_media_stream.h>

using namespace CustomMediaStream;
using FramePtr = ControllerHolder::FramePtr;
using Format = VideoFrame::Format;
using Plane = VideoFrame::Plane;
//v8::Global<v8::Object> control_handle;
//CustomMediaStream::VideoFrameCallback* callback;

NAN_METHOD(startCapture) {
  std::cerr << "addCaptureStreamToMediaStream" << info.Length() << std::endl;

  auto ctrl = ControllerHolder::create(info.GetIsolate(), info[0]->ToObject());
  if(ctrl == NULL) {
    Nan::ThrowTypeError("11111 cannot unwrap CustomMediaStream::ControllerHolder");
    return;
  }
  

  
  //int i = 1;
  // for (auto i = 0; i < 10000; i++) {
    auto frame = ctrl->allocate({0}, Format {100, 100});

    // void * dataY = frame->data(Plane::Y);
    // memset(dataY, 41, 1000);
    void * dataU = frame->data(Plane::U);
    memset(dataU, 161, 5000);
    void * dataV = frame->data(Plane::V);
    memset(dataV, 169, 5000);

    ctrl->queue({0}, std::move(frame));
  // }

    //auto frame = ctrl->allocate({0}, Format {100, 100});
  // for (auto i = 0; i < 10000; i++) {
  //int i = 1;
  //}

  
}

NAN_MODULE_INIT(custom_capturer_init) {
  Nan::Set(target, Nan::New("startCapture").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(startCapture)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE, custom_capturer_init);
