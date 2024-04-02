const db=require('../database');
const bcrypt=require('bcryptjs');

const card={
    getAllCard(callback){
        return db.query('SELECT * FROM card',callback);
    },
    getOneCard(id,callback){
        return db.query('SELECT * FROM card WHERE cardnumber=?',id,callback);
    },
    addCard(newCard,callback){
        bcrypt.hash(newCard.cardpin,10,function(err,hashPin){
            return db.query('INSERT INTO card(cardpin,cardtype,cardnumber) VALUES(?,?,?)',[hashPin,newCard.cardtype,newCard.cardnumber],callback);
        });
    },
    updateCard(id,updatecard,callback){
        bcrypt.hash(updatecard.cardpin,10,function(err,hashPin){
            return db.query('UPDATE card SET cardpin=?, cardtype=? WHERE cardnumber=?',[hashPin,updatecard.cardtype,id],callback)
        });
    },
    deleteCard(id,callback){
        return db.query('DELETE FROM card WHERE cardnumber=?',[id],callback);
    },
    login(cardnumber,callback){
        return db.query('SELECT cardpin FROM card WHERE cardnumber=?',[cardnumber],callback);
    }


}

module.exports=card;



