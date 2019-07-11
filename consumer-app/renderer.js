const { customMediaStream } = require('electron');
const capturer = require('capturer/build/Release/capturer.node');

const videoElem = document.getElementById('video-element');

let track = customMediaStream.createTrack({
    info: {
        resolution: { width: 1920, height: 1080 },
        frameRate: 30
    },
    startCapture: (controller) => {

        var a = capturer.startCapture(controller);
        // let i = 0;
        // this.interval = setInterval(() => {
        //     let frame = controller.allocateFrame();

        //     // frame.y, frame.u and frame.v are ArrayBuffers
        //     // containing pixels from each color plane
        //     console.log(frame);
        //     new Uint8Array(frame.y).fill((69 + i++) % 256); // filling the buffer with color red
        //     new Uint8Array(frame.u).fill(139);
        //     new Uint8Array(frame.v).fill(93);

        //     controller.queueFrame(frame, Date.now());
        // }, 1000);
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