
CREATE TABLE `playlist_music` (
  `playlist_id` bigint(20) NOT NULL,
  `music_id` INT(20) DEFAULT NULL,
  `music_name` VARCHAR(255) DEFAULT NULL,
  PRIMARY KEY (`playlist_id`,`music_id`),
)

CREATE TABLE `playlist` (
  `user_id` bigint(20) NOT NULL,
  `playlist_id` bigint(20) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `img` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`user_id`,`playlist_id`),
  unique(playlist_id)
)



create procedure fun(in id1 bigint(20),in id2 bigint(20))
begin
    select pm1.playlist_id,pm1.music_id,pm1.music_name
    from playlist p1,playlist_music pm1,playlist p2,playlist_music pm2
    where p1.user_id=id1
    and p1.playlist_id=pm1.playlist_id
    and p2.user_id=id2
    and p2.playlist_id=pm2.playlist_id
    and pm1.playlist_id=pm2.playlist_id
    and pm1.music_id=pm2.music_id
    group by pm1.playlist_id,pm1.music_id;
end;


create procedure fun(in id1 bigint(20),in id2 bigint(20))
begin
    select pm1.music_id,pm1.music_name
    from playlist p1,playlist_music pm1,playlist p2,playlist_music pm2
    where p1.user_id=id1
    and p1.playlist_id=pm1.playlist_id
    and p2.user_id=id2
    and p2.playlist_id=pm2.playlist_id
    and pm1.music_id=pm2.music_id
    group by pm1.music_id;
end;