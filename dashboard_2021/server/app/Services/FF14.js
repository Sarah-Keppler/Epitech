const Env = use('Env')
const fetch = require("cross-fetch");

function displayJobs(id) {
    const Http = new XMLHttpRequest();
    const url = "https://xivapi.com/character/" + id + "?data=";

    response = fetch(url, { mode: 'cors' })
        .then(response => {
            response.json().then(parsedJson => {
                console.log(`Display jobs of ${parsedJson.Character.Name}`)
                console.log("Jobs:");
                Object.entries(parsedJson.Character.ClassJobs).forEach((jobs) => {
                    Object.entries(jobs[1]).forEach((item) => {
                        if (item[0] == "Name")
                            console.log(`\tName: ${item[1]}`);
                        else if (item[0] == "Level")
                            console.log(`\tLevel: ${item[1]}`)
                    });
                    console.log("")
                });
            })
        });
}
