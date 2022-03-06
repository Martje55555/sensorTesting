const express = require('express');
const cors = require('cors');
const http = require('http')
const app = express();
const server = http.createServer(app);
const { Server } = require("socket.io");

const { exec } = require('./sensors.js');

const firebase = require('firebase-admin');

const serviceAccount = require("./admin.json");

const firebaseConfig = {
    credential: firebase.credential.cert(serviceAccount),
    databaseURL: "https://sdtest-849e7-default-rtdb.firebaseio.com"
};

firebase.initializeApp(firebaseConfig);

let database = firebase.database();

let tempRef = database.ref("temperature");


const io = new Server(server);

app.use(cors());

app.get('/', async (req, res) => {
    res.sendFile('/Users/martje/Desktop/sensorTesting/sensorTesing/client' + '/index.html');
});

io.on('connection', async (socket) => {
    console.log('socket connection successful')
    
   tempRef.once('value', (snapshot) => {
       console.log(snapshot.val());
   })

    socket.on('data', async (data) => {
        data = await exec();
        let time = new Date().toLocaleTimeString();
        let date = new Date().toLocaleDateString();
        let temp = data.temperature;
        let humidity = data.humidity;
        let result = ('Date: ' + date + ' Time: ' + time + ' temperature: ' + temp + ' ' + 'humidity: ' + humidity);        
            
        io.emit('data', result);
    });
});

server.listen(3001, () => {
    console.log('listening on *:3001');
});