//card taulujen operaatiot

const db=require('../database');

const card={
    getAllCard(callback){
        return db.query('SELECT * FROM card',callback);
    },
    getOneCard(id,callback){
        return db.query('SELECT * FROM card WHERE cardnumber=?',id,callback);
    },
    addCard(newCard,callback){
        return db.query('INSERT INTO card(cardpin,cardtype,cardnumber) VALUES(?,?,?)',[newCard.cardpin,newCard.cardtype,newCard.cardnumber],callback);
    },
    updateCard(id,updatecard,callback){
        return db.query('UPDATE card SET cardpin=?, cardtype=? WHERE cardnumber=?',[updatecard.cardpin,updatecard.cardtype,id],callback);
    },
    deleteCard(id,callback){
        return db.query('DELETE FROM card WHERE cardnumber=?',[id],callback);
    }


}

module.exports=card;

