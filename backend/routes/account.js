const express=require("express");
const router=express.Router();
const account=require("../models/account_model");

router.get("/",function(request, response){
    account.getAllAccount(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            console.log(result);
            response.json(result);
        }
        
    });
});

module.exports=router;