from firebase_admin import credentials,db,initialize_app


#credentials of the firebase app has to be placed here ( the json data file that can be downloaded form the firebase app`s console )
cred = credentials.Certificate({
  "insert cred here"
}
)

initialize_app(cred,{'databaseURL':'https://learn-ccd0a.firebaseio.com/'})
ref=db.reference("server/saving-data/fireblog")

def setmethod():
    user_ref=ref.child('users')    
    user_ref.set({
    'sanskar':{
        'date_of_birth':"sept 2, 1999",
        "full_name":"Sanskar Jain"
    },
    "shanu":{
        'date_of-birth':"Sept 1,1999",
        'Full_name':'Shanu Jain'
    }
    })
#direcly changing values of child

    user_ref.child('sanskar').set({
    "date-of-birth":"02/09/1999",
    "full_name":"Sanskar Jain"

    })
    user_ref.child('shanu').set({
    "date-of-birth":"01/09/1999",
    "full_name":"Shanu Jain"

    })
def updatemethod():
    #UPDATE METHOD
    user_ref=ref.child('users')
    user_ref=user_ref.child("sanskar")
    user_ref.update({
    'nickname':"Shanu"
    })


#.update({   "childnode/childnode/key":value   })
# Inthis secion we are actually chaging the cureent referency updating the value i.e we are going to child nodes then updateing their value because we are giving the path in keys whihc is actually modifying the current refernce of db
    user_ref=ref.child('users')
    user_ref.update({
    "sanskar/nickname":"shanu",
    "shanu/nickname":"sanskar"
    })

#in this as we are directly proving the value so the updation will be made in current refence instead of updating the child nodes.
#keys are main and if we provide the path in keys then updation will be done in the child nodes else the argument will be takes as value and update in users or current reference value is done directly.
    user_ref.update({
    'sanskar':{
        'nickname':'shanu'
    },
    'shanu':{
        'nickname':'neeraj'
    }

    })
def pushmethod():
#push lets multiple writes at the same time by providing unique key to each child so that none of the data is deleted and the data is stored in different child
    posts_ref=ref.child("post")
    posts_ref=posts_ref.push()
    posts_ref.set({
    'author':'sanskar',
    "title":'COBOL- A new programming language'
    })
    #Resetting the posts_ref becuase it was modified by .push method above
    posts_ref=ref.child("post")
    posts_ref.push().set({
        "author":'aman',
        'title':'History of Java'
    })

    posts_ref.push({
        'Author':"ROhit",
        "Titile":'God of programming languages'
    })


def increment_votes(current_value):
    print(current_value)
    return current_value +1 if current_value else 1
def transactionoperation():
    upvotes_ref=db.reference('server/saving-data/fireblog/post/-M1ywma0-tXjnqRvOBQT/upvotes')
    try:
        new_vote_count=upvotes_ref.transaction(increment_votes)
        print(type(new_vote_count))
        print("transaction completed")
    except db.TransactionAbortedError:
        print('Transaction failed to commit')