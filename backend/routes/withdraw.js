const express = require('express');
const router = express.Router();
const withdraw = require('../models/withdraw_model');

router.post('/', function(request, response){
    withdraw.withdraw(request.body, function(err, result){
        if (err) {
            response.send(err);
        }else{
            response.json(result);
        }
    });
});

module.exports = router;