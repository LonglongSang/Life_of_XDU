create table flights
(
	flight_id int not null,
	price double not null,
	num_seat int not null,
	num_avail int not null,
	from_city int not null,
	to_city int not null,
	constraint flights_pk
		primary key (flight_id)
);

create table hotels
(
	city int not null,
	price double not null,
	num_room int not null,
	num_avail int not null,
	from_city int not null,
	constraint hotels_pk
		primary key (city)
);


create table bus
(
	city int not null,
	price double not null,
	num_bus int not null,
	num_avail int not null,
	constraint bus_pk
		primary key (city)
);

create table customers
(
	customer_id int not null,
	name varchar(32) not null,
	constraint customers_pk
		primary key (customer_id)
);


create table reservation
(
	customer_id int not null,
	reser_typ int not null,
	reser_id int not null,
	constraint reservation_pk
		primary key (reser_id),
	constraint fk
		foreign key (customer_id) references customers (customer_id)
);


