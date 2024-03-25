//card taulujen operaatiot

const db=require('../database');

const card={
    getAllCard(callback){
        return db.query('SELECT cardnumber, cardtype FROM card',callback);
    },
    getOneCard(callback){
        return db.query('SELECT cardnumber FROM card WHERE')
    }
}

module.exports=card;


/*
Operaatiot:
Lisää kortti
Poista kortti
Päivitä kortti
Etsi kortti


*/