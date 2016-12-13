var max = 4;
var min = 1;
var randomNum=Math.floor(Math.random()*(max-min) + min);

var res, search = null;

var arr = new Array();
for (var i = 0; i < randomNum; i++) {
	res = $.ajax({
	    url: 'https://wordsapiv1.p.mashape.com/words/', // The URL to the API. You can get this by clicking on "Show CURL example" from an API profile
	    type: 'GET', // The HTTP Method, can be GET POST PUT DELETE etc
	    data: {
	    	random: true
	    }, // Additional parameters here
	    dataType: 'json',
	    success: function(data) {
		    	//
	        //Change data.source to data.something , where something is whichever part of the object you want returned.
	        //To see the whole object you can output it to your browser console using:
	        //console.log(data);
	       	// document.getElementById("output").innerHTML = data.source; 
	       	// console.log("data: ", data);
	       	arr.push(data.word);

					search = arr.join(' ');

					console.log("search: ", search);
        },
	    error: function(err) { alert(err); },
	    beforeSend: function(xhr) {
		    xhr.setRequestHeader("X-Mashape-Authorization", "g1WKM57nOamshv6SCKLjcogQs40lp1BFSxdjsn8cJosWzWJuQM"); // Enter here your Mashape key
	    }
	});
};

while(search == null) { ; }

console.log("search: ", search);
// search;
