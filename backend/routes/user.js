const express=require('express');
const router=express.Router();
const user=require('../models/user_model');

router.get('/',function(request, response){
    user.getAllUser(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.get('/:id',function(request, response){
    user.getOneUser(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.post('/',function(request, response){
    user.addUser(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.put('/id',function(request, response){
    user.updateUser(request.params.idcustomer, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.delete('/id',function(reguest, response){
    user.deleteUser(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});


modelu.exports=router;