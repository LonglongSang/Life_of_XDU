/*
flights(flight_id,price,num_seat,num_avail,from_city,to_city) primary_key=flight_id
hotels(city,price,num_room,num_avail) primary_key=city
bus(city,price,num_bus,num_avail) primary_key=city
customers(customer_id,name,password,age,gender) primary_key=customer_id
reservation(customer_id,reser_typ,reser_id,from_city,to_city) primary_key=reser_id
*/
/*
1．	航班，大巴车，宾馆房间和客户基础数据的入库，更新（表中的属性也可以根据你的需要添加）。
*/
--航班信息入库
create procedure insertIntoFlights
(in a int,in b double,in c int,in d int,in e int,in f int)
begin
    insert into 
    flights(flight_id,price,num_seat,num_avail,from_city,to_city) 
    values (a,b,c,d,e,f);
end;

--航班信息更新
create procedure updateFlights
(in a int,in b double,in c int,in d int,in e int,in f int)
begin
    update
        flights
    set
        flights.price=b,
        flights.num_seat=c,
        flights.num_avail=d,
        flights.from_city=e,
        flights.to_city=f
    where
        flights.flight_id=a
end;

--巴士信息入库
create procedure insertIntoBus
(in a int,in b double,in c int,in d int)
begin
    insert into 
    bus(city,price,num_bus,num_avail)
    values (a,b,c,d);
end;

--巴士信息更新
create procedure updateBus
(in a int,in b double,in c int,in d int)
begin
    update
        bus
    set
        bus.price=b,
        bus.num_bus=c,
        bus.num_avail=d
    where
        bus.city=a
end;

--宾馆信息入库
create procedure insertIntoHotel
(in a int,in b double,in c int,in d int)
begin
    insert into 
    bus(city,price,num_room,num_avai)
    values (a,b,c,d);
end;

--宾馆信息更新
create procedure updateHotel
(in a int,in b double,in c int,in d int)
begin
    update
        bus
    set
        hotels.price=b,
        hotels.num_room=c,
        hotels.num_avail=d
    where
        hotels.city=a
end;

--客户信息入库
create procedure insertIntoCustomers
(in a int,in b varchar(32),in c char(32),in d int,in e char(1))
begin
    insert into 
    customers(customer_id,name,password,age,gender)
    values (a,b,c,d,e);
end;

--客户信息更新
create procedure updateCustomers
(in a int,in b varchar(32),in c char(32),in d int,in e char(1))
begin
    update
        customers
    set
        customers.name=b
        customers.password=c
        customers.age=d
        customers.gender=e
    where
        customers.customer_id=a
end;





/*
2．	预定航班，大巴车，宾馆房间。
*/

--预定航班 id客户想要预定从fromCity到toCity的航班
create procedure bookFlight(in id int,in fromCity int,in toCity int)
label:begin
    declare tot int default 0;
    declare avail int default 0;
    select @tot=count(1) from customers where customers.customer_id=id;
    /*检查用户id是否不存，不存在直接退出*/
    if tot=0 then
        leave label;
    end if;

    set tot=0;
    set avail=0;
    select flights.num_avail,flights.num_seat into @avail,@tot from flights where fromCity=flights.from_city and toCity=flights.to_city;
    
    /*检查该航班的num_seat是否为0，或者不存在，或者是否已经坐满*/
    if tot=avail  or tot=0 then
        leave label;
    end if;

    set tot=0;

    
    select
        @tot=count(1)
    from
        reservation
    where
        reservation.customer_id=id
    and
        reservation.reser_typ=1
    and
        reservation.from_city=fromCity
    and
        reservation.to_city=toCity;
    
    /*检查该用户是否已经预定过该航班*/
    if tot<>0 then
        leave label;
    end if;

    /*检查完成，可以更新数据*/
    /*航班的num_avail减1*/
    update
        flights
    set
        flights.num_avail=flights.num_avail-1
    where
        flights.from_city=fromCity
    and
        flights.to_city=toCity;

    /*将该条预定信息插入reservation*/ 
    insert into
        reservation(customer_id,reser_typ,from_city,to_city)
    values
        (id,1,fromCity,toCity);
end;

--预定酒店，id客户想要预定tarCity的酒店
create procedure bookHotel(in id int,in tarCity int)
label:begin
    declare tot int default 0;
    declare avail int default 0;
    select @tot=count(1) from customers where customers.customer_id=id;
    /*检查用户id是否不存，不存在直接退出*/
    if tot=0 then
        leave label;
    end if;

    set tot=0;
    set avail=0;
    select hotels.num_avail,hotels.num_room into @avail,@tot from hotels where hotels.city=tarCity;
    
    /*检查该城市的hotel的num_room是否为0，或者不存在，或者是否已经坐满*/
    if tot=avail  or tot=0 then
        leave label;
    end if;

    set tot=0;

    
    select
        @tot=count(1)
    from
        reservation
    where
        reservation.customer_id=id
    and
        reservation.reser_typ=2
    and
        reservation.from_city=tarCity;
    
    /*检查该用户是否已经预定过该bus*/
    if tot<>0 then
        leave label;
    end if;

    /*检查完成，可以更新数据*/
    /*bus的num_bus减1*/
    update
        hotels
    set
        hotels.num_avail=hotels.num_avail-1
    where
        hotels.city=tarCity;

    /*将该条预定信息插入reservation*/ 
    insert into
        reservation(customer_id,reser_typ,tarCity)
    values
        (id,2,fromCity);
end;

--预定bus id客户想要预定tarCity的bus
create procedure bookBus(in id int,in tarCity int)
label:begin
    declare tot int default 0;
    declare avail int default 0;
    select @tot=count(1) from customers where customers.customer_id=id;
    /*检查用户id是否不存，不存在直接退出*/
    if tot=0 then
        leave label;
    end if;

    set tot=0;
    set avail=0;
    select bus.num_avail,bus.num_bus into @avail,@tot from bus where bus.city=tarCity;
    
    /*检查该城市的bus的num_bus是否为0，或者不存在，或者是否已经坐满*/
    if tot=avail  or tot=0 then
        leave label;
    end if;

    set tot=0;

    select
        @tot=count(1)
    from
        reservation
    where
        reservation.customer_id=id
    and
        reservation.reser_typ=3
    and
        reservation.from_city=tarCity;
    
    /*检查该用户是否已经预定过该bus*/
    if tot<>0 then
        leave label;
    end if;

    /*检查完成，可以更新数据*/
    /*bus的num_bus减1*/
    update
        bus
    set
        bus.num_avail=bus.num_avail-1
    where
        bus.city=tarCity;

    /*将该条预定信息插入reservation*/ 
    insert into
        reservation(customer_id,reser_typ,tarCity)
    values
        (id,3,fromCity);
end;





/*3.查询航班，大巴车，宾馆房间，客户和预订信息。*/

--查询从目的地或起始地为city的航班
create procedure queryFlight(in city int)
begin
    select
        flights.*
    from
        flights
    where
        flights.from_city=city
    or
        flights.to_city=city
    order by
        flights.num_avail desc;
end;

--查询tarCity的hotel
create procedure queryHotel(in tarCity int)
begin
    select
        hotels.*
    from
        hotels
    where
        hotels.city=tarCity
end;

--查询tarCity的bus
create procedure queryBus(in tarCity int)
begin
    select
        bus.*
    from
        bus
    where
        bus.city=tarCity
end;

--查询id客户的所有预订信息
create procedure queryReservation(in id int)
begin
    select
        (
            case
                when r.reser_typ=1 then "flight"
                when r.reser_typ=2 then "hotel"
                else "bus"
            end
        ) as "type",
        r.from_city,
        (
            case
                when r.reser_typ=1 then r.to_city
                else "none"
            end
        ) as "to_city"
    from
        reservation as r
    where
        r.customer_id=id;
end;




/*4、查询某个客户的旅行线路*/
create procedure queryRoute(in id int)
begin
    select
        distinct(r.from_city)
    from
        reservation r
    where
        r.customer_id=id
    union
    select
        distinct(r.to_city)
    from
        reservation r
    where
        r.customer_id=id
    and
        r.to_city<>NULL;
end;