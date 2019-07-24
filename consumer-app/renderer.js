const { customMediaStream } = require('electron');
const capturer = require('capturer/build/Debug/capturer.node');

const videoElem = document.getElementById('video-element');

let track = customMediaStream.createTrack({
    info: {
        resolution: { width: 1920, height: 1080 },
        frameRate: 30
    },
    startCapture: (controller) => {
        capturer.startCapture(controller);
    },
    stopCapture: () => {
        clearInterval(this.interval);
    }
})

let mediaStream = new MediaStream();
mediaStream.addTrack(track);

//this is a html5 video element
videoElem.srcObject = mediaStream
videoElem.play();