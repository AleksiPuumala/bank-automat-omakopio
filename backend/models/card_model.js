//card taulujen operaatiot

const db=require('../database');

const card={
    getAllCard(callback){
        return db.query('SELECT cardnumber, cardtype FROM card',callback);
    },
    getOneCard(callback){
        return db.query('SELECT cardnumber FROM card WHERE',callback);
    },
    getCardPIN(id, callback){
        return db.query("SELECT cardpin FROM card INNER JOIN cardtype on card.cardnumber=cardtype.cardnumber WHERE idaccount=?",[id],callback);
    }
}

module.exports=card;