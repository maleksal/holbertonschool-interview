#!/usr/bin/node

const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const chars = JSON.parse(body).characters;

      for (let i = 0; i < chars.length; i++) {
        const name = await new Promise(function (resolve, reject) {
          request(chars[i], function (error, response, body) {
            if (error) {
              reject(error);
            } else { resolve(JSON.parse(body).name); }
          });
        });
        console.log(name);
      }
    }
  });
