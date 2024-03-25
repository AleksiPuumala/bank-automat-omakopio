const express=require('express');
const router=express.Router();
const card = require('../models/card_model');

router.get('/',function(request,response){
    card.getAllCard(function(err, result){
        if(err){
            response.send(err);
        }
        else {
            console.log(result);
            response.json(result);
        }
    })
})

module.exports=router;