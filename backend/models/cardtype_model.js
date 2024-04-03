const db=require('../database');

const cardtype={
    getAllCardtype(callback){
        return db.query('SELECT * FROM cardtype',callback);
    },
    getOneCardtype(id, callback){
        return db.query('SELECT * FROM cardtype WHERE idcard=?',id,callback);
    },
    addCardtype(newCardtype, callback){
        return db.query('INSERT INTO cardtype (idaccount, cardnumber) VALUES (?,?)',[newCardtype.idaccount,newCardtype.cardnumber],callback);
    },
    updateCardtype(id,updateData, callback){
        return db.query('UPDATE cardtype SET idaccount=?,cardnumber=? WHERE idcard=?',[updateData.idaccount,updateData.cardnumber,id],callback);
    },
    deleteCardtype(id,callback){
        return db.query('DELETE FROM cardtype WHERE idcard=?',id,callback);
    }
}
module.exports=cardtype;