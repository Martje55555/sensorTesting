const express = require('express');
const cors = require('cors');
const http = require('http')
const app = express();
const server = http.createServer(app);
const {Server} = require("socket.io");

const {exec} = require('./sensors.js');

const io = new Server(server);

app.use(cors());

app.get('/', async (req, res) => {
    //res.sendFile('/Users/martje/Desktop/sensorTesting/sensorTesing/client' + '/index.html');
    res.sendFile('/home/parallels/sensorTesting/client' + '/index.html');
});

io.on('connection', async (socket) => {
    console.log('socket connection successful')
    
    socket.on('data', async (data) => {
        data = await exec();
        let temp = data.temperature;
        let humidity = data.humidity;
        let result = ('temperature: ' + temp + ' ' + 'humidity: ' + humidity);
        console.log(result);
        io.emit('data', result);
    });
});

server.listen(3001, () => {
    console.log('listening on *:3001');
});