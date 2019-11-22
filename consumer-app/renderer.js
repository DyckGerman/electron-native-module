const { customMediaStream } = require('electron');
const capturer = require('capturer/build/Release/capturer.node');
const videoElem = document.getElementById('video-element');

/// attach debugger to that pid
console.log('pid ' + process.pid);

/// call this function from dev console
function start() {
    let trackInfo = {
        resolution: { width: 1920, height: 1080 },
        frameRate: 30
    };
    
    console.log('before createTrack');
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

    console.log('before MediaStream');
    let mediaStream = new MediaStream();
    mediaStream.addTrack(track);

    console.log('before srcObject');
    //this is a html5 video element
    videoElem.srcObject = mediaStream
    videoElem.play();
}

function stop() {
    videoElem.srcObject = null;
    //videoElem.stop();
}