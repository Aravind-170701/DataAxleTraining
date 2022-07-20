import { useState, useEffect } from "react"
import axios from 'axios';
import logo from '../images/download.png'
import '../App.css' 

const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs'

const Forms = () => {

    let formData = {
        "title" : "",
        "description" : "",
        "author" : "",
        "reading_time" : "" 
    }

    const[currentFormData, setFormData] = useState(formData)

    function handleSubmit(event) {

        formData["title"] = event.target[0].value
        formData["description"] = event.target[1].value
        formData["author"] = event.target[2].value
        formData["reading_time"] = event.target[3].value

        console.log("hello",formData)
        console.log("hello",currentFormData)

        setFormData(formData)

        console.log("hello",currentFormData)

        axios.post(baseURL, currentFormData,{
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then((response) => {
            console.log('data', response)
        });
    }


    return (  
        <div>
            <br></br>
            <br></br>
            <br></br>
            <br></br>
            <br></br>

            <div className="container" id="mainBody">
                <div className="row">
                    <div className="col">
                        <div className="card" id="leftCard">
                            <div className="card-body">
                                
                            </div>
                        </div>
                    </div>

                    <div className="col">
                        <div className="card">
                            <div className="card-body">
                                <form onSubmit={handleSubmit}>
                                    <br></br>
                                    <div className="form-group row">
                                        <label for="title" className="col-sm-2 col-form-label">Title:</label>
                                        <div className="col-sm-10">
                                            <input type="text" className="form-control" id="title" placeholder="Title"></input>
                                        </div>
                                    </div>

                                    <br></br>

                                    <div className="form-group row">
                                        <label for="description" className="col-sm-2 col-form-label">Description:</label>
                                        <div className="col-sm-10">
                                            <input type="text" className="form-control" id="description" placeholder="Description"></input>
                                        </div>
                                    </div>

                                    <br></br>

                                    <div className="form-group row">
                                        <label for="author" className="col-sm-2 col-form-label">Author:</label>
                                        <div className="col-sm-10">
                                            <input type="text" className="form-control" id="author" placeholder="Author"></input>
                                        </div>
                                    </div>

                                    <br></br>

                                    <div className="form-group row">
                                        <label for="reading_time" className="col-sm-2 col-form-label">Reading Time:</label>
                                        <div className="col-sm-10">
                                            <input type="text" className="form-control" id="reading_time" placeholder="Reading Time"></input>
                                        </div>
                                    </div>

                                    <br></br>

                                    <div className="form-group row">
                                        <div className="col-sm-10">
                                        <button type="submit" class="btn btn-primary">Add Blog</button>
                                        </div>
                                    </div>

                                    <br></br>
                                </form>
                            </div>
                        </div>
                    </div>
                </div>
            </div>




           

                
        </div>
    );
}
 
export default Forms;
