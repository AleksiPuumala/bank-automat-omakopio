const express=require('express');
const router=express.Router();
const customer=require('../models/customer_model');

router.get('/',function(request, response){
    customer.getAllCustomer(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.get('/',function(request,response){
    customer.getOneCustomer(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.post('/',function(request, response){
    customer.addCustomer(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.put('/', function(request, response){
    customer.updateCustomer(request.params.idcustomer, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    });
});
router.delete('/', function(request, response){
    customer.deleteCustomer(request.params.idcustomer, function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.json(result);
        }
    })
})


module.exports=router;