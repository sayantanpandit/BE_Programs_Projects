states_of_india('Maharashtra').
states_of_india('Bihar').
states_of_india('West bengal').
states_of_india('Uttar Pradesh').
capital_of('Maharastra','Mumbai').
capital_of('Bihar','Patna').
capital_of('West Bengal','Kolkata').
capital_of('Uttar Pradesh','Kanur').
flows_through('West Bengal','Ganga').
flows_through('West Bengal','Damodar').
flows_through('West Bengal','Mahananda').
flows_through('Bihar','Ganga').
flows_through('Uttar Pradesh','Ganga').
flows_through('Uttar Pradesh','Jamuna').
flows_through('Uttar Pradesh','Gomti').
flows_through('Maharastra','Krishna').
flows_through('Maharastra','Godavari').
flows_through('Maharastra','Tapi').
flows_through('Maharastra','Panchganga').
spoken_in('West Bengal','Bengali').
spoken_in('Maharastra','Marathi').
spoken_in('Uttar Pradesh','Hindi').
spoken_in('Bihar','Hindi').
spoken_near(River,Lang):-flows_through(State,River),spoken_in(State,Lang).
/*Both River,Lang are variables*/

