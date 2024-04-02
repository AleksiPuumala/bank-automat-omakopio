const db=require("../database");

const account={
    getAllAccount(callback){
        return db.query("SELECT * FROM account",callback);

    },
    getOneAccount(id,callback){ 
        return db.query("SELECT * FROM account WHERE idaccount=?",id,callback);

    },
     addOneAccount(newaccount,callback){
        return db.query("INSERT INTO account(idaccount, balance, creditlimit) VALUES(?,?,?)"[newaccount.idaccount, newaccount.balance, newaccount.creditlimit],callback)
     },
     updateOneAccount(id,updateaccount,callback){
        return db.query("UPDATE account SET idaccount=?, balance=?, creditlimit=? "[updateaccount.idaccount,updateaccount.balance,updateaccount.creditlimit],callback)
     },
     deleteOneAccount(id,callback){
        return db.query("DELETE FROM account WHERE idaccount=?",id,callback);
     },

    //add, update, delete

    
}
module.exports=account;