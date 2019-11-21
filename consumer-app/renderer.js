const { customMediaStream } = require('electron');
const capturer = require('capturer/build/Release/capturer.node');

const videoElem = document.getElementById('video-element');

console.log('before createTrack');

let trackInfo = {
    resolution: { width: 1920, height: 1080 },
    frameRate: 30
};

let track = customMediaStream.createTrack(
    trackInfo,
    (controller) => {
        console.log('startCapture controller = ' + controller);
        capturer.startCapture(controller);
    },
    () => {
        console.log('stopCapture');
        clearInterval(this.interval);
    }
)

let mediaStream = new MediaStream();
mediaStream.addTrack(track);

//this is a html5 video element
videoElem.srcObject = mediaStream
videoElem.play();