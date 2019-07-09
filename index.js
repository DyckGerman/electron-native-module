const { app, BrowserWindow } = require('electron');
// const capturer = require('./native_module/build/Release/addon');

// console.log(addon.hello());

app.once('ready', () => {
    let win = new BrowserWindow({
        backgroundColor: '#444444',
        webPreferences: {
            nodeIntegration: true,
        }
    });

    win.webContents.openDevTools();
    console.log(__dirname);
    win.loadURL(`file://${__dirname}/renderer.html`);
});
