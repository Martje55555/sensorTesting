const sensor = require('node-dht-sensor').promises;

sensor.initialize({
    test: {
        fake: {
          temperature: 21,
          humidity: 60
        }
      }
});
 
async function exec() {
  try {
    return await sensor.read(11, 2);
    console.log(
      `temp: ${res.temperature.toFixed(1)}°C, ` +
        `humidity: ${res.humidity.toFixed(1)}%`
    );
  } catch (err) {
    console.error("Failed to read sensor data:", err);
  }
}
 
module.exports = { exec };