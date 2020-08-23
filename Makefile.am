ACLOCAL_AMFLAGS= -I m4
AUTOMAKE_OPTIONS= subdir-objects

noinst_LIBRARIES = libperftest.a
libperftest_a_SOURCES = src/get_clock.c src/perftest_communication.c src/perftest_parameters.c src/perftest_resources.c src/perftest_counters.c
noinst_HEADERS = src/get_clock.h src/perftest_communication.h src/perftest_parameters.h src/perftest_resources.h src/perftest_counters.h

bin_PROGRAMS = send_bw send_lat write_lat write_bw read_lat read_bw atomic_lat atomic_bw ud_lat rc_lat rc_async rc_busy_polling_lat many_to_one

rc_busy_polling_lat_SOURCES = src/rc_busy_polling_lat.c
rc_busy_polling_lat_LDADD = $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA) 

many_to_one_SOURCES = src/many_to_one/main.cpp src/many_to_one/rdma.hpp src/many_to_one/rdma.cpp
many_to_one_LDADD = $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA) 

ud_lat_SOURCES = src/ud_lat.c
ud_lat_LDADD = $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

rc_async_SOURCES = src/async/rc_async.c
rc_async_LDADD = $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

rc_lat_SOURCES = src/rc_lat.c
rc_lat_LDADD = $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

send_bw_SOURCES = src/send_bw.c src/multicast_resources.c src/multicast_resources.h
send_bw_LDADD = libperftest.a $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

send_lat_SOURCES = src/send_lat.c src/multicast_resources.c src/multicast_resources.h
send_lat_LDADD = libperftest.a $(LIBUMAD) $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

write_lat_SOURCES = src/write_lat.c
write_lat_LDADD = libperftest.a $(LIBMATH)  $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

write_bw_SOURCES = src/write_bw.c
write_bw_LDADD = libperftest.a $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

read_lat_SOURCES = src/read_lat.c
read_lat_LDADD = libperftest.a $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

read_bw_SOURCES = src/read_bw.c
read_bw_LDADD = libperftest.a $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

atomic_lat_SOURCES = src/atomic_lat.c
atomic_lat_LDADD = libperftest.a $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

atomic_bw_SOURCES = src/atomic_bw.c
atomic_bw_LDADD = libperftest.a $(LIBMATH) $(LIBMLX4) $(LIBMLX5) $(LIBEFA)

