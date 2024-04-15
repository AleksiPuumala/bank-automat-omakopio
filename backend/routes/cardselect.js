const express=require('express');
const router=express.Router();
const cardselect = require('../models/cardselect_model');

router.get('/:id',function(request,response){
    cardselect.getCardAccount(request.params.id,function(err, result){
        if (err){
            response.send(err);
        } else {
            response.json(result);
        }
    })
})

module.exports=router;