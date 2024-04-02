const express=require('express');
const router=express.Router();
const account = require('../models/account_model');

router.get('/',function(request,response){
    account.getAllAccount(function(err, result){
        if(err){
            response.send(err);
        }
        else {
            console.log(result);
            response.json(result);
        }
    });
});

router.get('/:id',function(request,response){
    account.getOneAccount(request.params.id,function(err, result){
        if(err){
            response.send(err);
            console.log("error");
        } else {
            console.log(result);
            response.json(result[0]);
        }
    });
});

router.post('/',function(request,response){
    account.addOneAccount(request.body,function(err,result){
        if(err){
            response.send(err);
            console.log('addOneAccount error');
        }else{
            console.log(result);
            response.json(result.affectedRows);
        }
    })
});

router.put('/:id',function(request,response){
    account.updateOneAccount(request.params.id, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.delete('/:id',function(request,response){
    account.deleteOneAccount(request.params.id,function(err,result){
        if(err){
            response.send(err);
        } else {
            response.json(result.affectedRows);
        }
    })
});

module.exports=router;