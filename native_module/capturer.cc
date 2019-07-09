#include <nan.h>
#include <node_api.h>
#include <electron/shell/common/api/custom_media_stream.h>

namespace demo {

NAN_METHOD(startCapture) {
  // std::cerr << "addCaptureStreamToMediaStream" << info.Length() << std::endl;

  // if(info.Length() < 1) {
  //   Nan::ThrowTypeError("not enough arguments");
  //   return;
  // }

  // auto cb = CMS::VideoFrameCallbackHolder::unwrap(info.GetIsolate(), info[0]->ToObject());

  // if(!cb) {
  //   Nan::ThrowTypeError("cannot unwrap CustomMediaStream::VideoFrameCallback");
  //   return;
  // }

  // callback = cb;

  // std::vector<capturer::SourceId> params;
  // if(info.Length() > 1) params = extractIds(info[1]);

  // capture_session = capturer::create(params.size() ? params[0] : capturer::SourceId{capturer::SourceType::display, 0});

  // start(capture_session, callback);  
}

napi_value Method(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
  if (status != napi_ok) return nullptr;
  return greeting;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", fn);

  CustomMediaStream::Format someCb;
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo