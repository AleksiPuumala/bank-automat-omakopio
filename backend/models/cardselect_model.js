const db=require('../database');

const cardselect={
    getCardAccount(id,callback){
        return db.query('SELECT idaccount FROM cardtype WHERE cardnumber=?',id, callback)
    }
}




module.exports=cardselect;