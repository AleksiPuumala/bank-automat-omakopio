const express=require('express');
const router=express.Router();
const cardtype=require('../models/cardtype_model');

router.get('/',function(request, response){
    cardtype.getAllCardtype(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.get('/:id',function(request, response){
    cardtype.getOneCardtype(request.params.id,function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.post('/',function(request, response){
    cardtype.addCardtype(request.body,function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.put('/:id',function(request, response){
    cardtype.updateCardtype(request.params.id, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.delete('/:id',function(request, response){
    cardtype.deleteCardtype(request.params.id,function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});


module.exports=router;