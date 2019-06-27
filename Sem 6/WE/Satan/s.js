var express = require('express');
var app = express();

app.get('/', function(req, res){
	var today = new Date()
	h = today.getHours()
	m = today.getMinutes()
	if ((h==12 || h==24 || h==0) && m==0){

	} else 
	   res.send("Try again at 1");
});

app.listen(3000);
