const db=require("../database");

const account={
    getAllAccount(callback){
        return db.query("SELECT * FROM account",callback);
    },
    getOneAccount(id,callback){ 
        return db.query("SELECT * FROM account WHERE idaccount=?",id,callback);
    },
     addOneAccount(newaccount,callback){
        return db.query("INSERT INTO account(idaccount,balance,creditlimit,accounttype) VALUES(?,?,?,?)",[newaccount.idaccount, newaccount.balance, newaccount.creditlimit, newaccount.accounttype],callback)
     },
     updateOneAccount(id,updateaccount,callback){
        return db.query("UPDATE account SET balance=?, creditlimit=?, accounttype=? WHERE idaccount=?",[updateaccount.balance,updateaccount.creditlimit,updateaccount.accounttype,id],callback)
     },
     deleteOneAccount(id,callback){
        return db.query("DELETE FROM account WHERE idaccount=?",id,callback);
     },


    
}
module.exports=account;