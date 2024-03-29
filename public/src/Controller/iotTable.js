const { openDb } = require("../configDB.js");
const fetch = require("node-fetch");

const timestampRegex = /(?<date>[\d\-]*)T(?<stamp>[\d\:]*).(?<trash>[\d]*)Z/;

// Funçaõ assíncrona para peghar os dados do broker
async function insertTable() {
  var db;
  var consumption;
  var timestamp;
  var date;
  var today = new Date();
  var endTime = new Date();
  var startTime = new Date();

  // pega o tempo final que seria a hora atual
  var date =
    today.getFullYear() + "-" + (today.getMonth() + 1) + "-" + today.getDate();
  var time =
    today.getHours() + 10 + ":" + today.getMinutes() + ":" + today.getSeconds();
  var dateTime = date + " " + time;
  endTime = dateTime;

  // pega o tempo final que seria a hora atual - 2 horas
  var date =
    today.getFullYear() + "-" + (today.getMonth() + 1) + "-" + today.getDate();
  var time =
    today.getHours() - 2 + ":" + today.getMinutes() + ":" + today.getSeconds();
  var dateTime = date + " " + time;
  startTime = dateTime;

  // url padronixada para retornar dados
  var key = "6615871e-6222-4e2e-9325-f02e611ff39f";
  var url =
    "https://api.tago.io/data?variable=valor1&start_date=" +
    startTime.toString() +
    "&end_date=" +
    endTime.toString();

  console.log(url);

  // insere dados nas tabelas os dados necessarios
  function insertConsumption(timestamp, consumption, dateday) {
    openDb().then((db) => {
      db.run(
        "INSERT or IGNORE INTO consumption (dateday, timestamp, id_property, gasto) VALUES (?,?,?,?)",
        dateday,
        timestamp,
        1,
        consumption
      );
    });
  }

  fetch(url, {
    method: "GET",

    headers: {
      Authorization: "6615871e-6222-4e2e-9325-f02e611ff39f",
    },
  })
    .then((res) => res.json())
    .then((json) => {
      db = json;
      console.log(db);
      for (var i = 0; i < db["result"].length; i++) {
        timestamp = db["result"][i].time;

        var match = timestamp.match(timestampRegex);
        let singleDate = match.groups.date;
        let singleStamp = match.groups.stamp;

        timestamp = singleDate + " " + singleStamp; // 2022-06-05 22:30:00
        date = singleDate; // 2022-06-05
        consumption = db["result"][i].value; // 12

        insertConsumption(timestamp, consumption, date);
      }
    })
    .catch((err) => console.log(err));
}

module.exports = { insertTable };
