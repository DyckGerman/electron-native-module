#include <utility>
#include <iostream>

#include <nan.h>
#include <custom_media_stream.h>

using namespace CustomMediaStream;
using FramePtr = ControllerHolder::FramePtr;
using Format = VideoFrame::Format;
using Plane = VideoFrame::Plane;

NAN_METHOD(startCapture) {
  std::cerr << "addCaptureStreamToMediaStream" << info.Length() << std::endl;

  auto ctrl = ControllerHolder::create(info.GetIsolate(), info[0]->ToObject());
  if(ctrl == NULL) {
    Nan::ThrowTypeError("11111 cannot unwrap CustomMediaStream::ControllerHolder");
    return;
  }

  //for (int i = 0; i < 10; i++) {
    auto frame = ctrl->allocate(0, Format {100, 100});
 
    void * dataY = frame->data(Plane::Y);
    memset(dataY, 100, 1000);
    void * dataU = frame->data(Plane::U);
    memset(dataU, 0, 3000);
    void * dataV = frame->data(Plane::V);
    memset(dataV, 0, 5000);

    ctrl->queue(0, std::move(frame));
  //}
}

NAN_MODULE_INIT(custom_capturer_init) {
  Nan::Set(target, Nan::New("startCapture").ToLocalChecked(), Nan::GetFunction(Nan::New<v8::FunctionTemplate>(startCapture)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE, custom_capturer_init);
