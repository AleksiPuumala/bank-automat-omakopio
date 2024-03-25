const { query } = require('express');
const db=require('../database');

const customer={
    getAllCustomer(callback){
        return db.query("SELECT * FROM customer",callback);
    }
}

module.exports=customer;