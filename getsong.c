
#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include <mpd/message.h>

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define RED "\x1b[31;01m"
#define DARKRED "\x1b[31;06m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32;06m"
#define YELLOW "\x1b[33;06m"
#define CYAN "\x1b[36;01m"

static int
handle_error(struct mpd_connection *c)
{
	assert(mpd_connection_get_error(c) != MPD_ERROR_SUCCESS);

	fprintf(stderr, "%s\n", mpd_connection_get_error_message(c));
	mpd_connection_free(c);
	return EXIT_FAILURE;
}

static void
print_tag(const struct mpd_song *song, enum mpd_tag_type type)
{
	unsigned i = 0;
	const char *value;

	while ((value = mpd_song_get_tag(song, type, i++)) != NULL)
		printf("%s\n", value);
}
static void
print_songname(const struct mpd_song *song, enum mpd_tag_type type)
{
	unsigned i = 0;
	const char *value;

	while ((value = mpd_song_get_tag(song, type, i++)) != NULL)
		printf(GREEN"Now playing:"RESET" %s\n", value);
}
static void
print_songartist(const struct mpd_song *song, enum mpd_tag_type type)
{
	unsigned i = 0;
	const char *value;

	while ((value = mpd_song_get_tag(song, type, i++)) != NULL)
		printf(""" %s\n", value);
}

int songmain() {
	int argc = 1;
	struct mpd_connection *conn;

	conn = mpd_connection_new(NULL, 0, 30000);

	if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS)
		return handle_error(conn);

	{
		
	}

	if(argc==1) {
		struct mpd_status * status;
		struct mpd_song *song;
		const struct mpd_audio_format *audio_format;

		mpd_command_list_begin(conn, true);
		mpd_send_status(conn);
		mpd_send_current_song(conn);
		mpd_command_list_end(conn);

		mpd_response_next(conn);

		while ((song = mpd_recv_song(conn)) != NULL) {
			print_songname(song, MPD_TAG_TITLE);
			print_songartist(song, MPD_TAG_ARTIST);
			print_tag(song, MPD_TAG_ALBUM);
		//	print_tag(song, MPD_TAG_TRACK, "track");
		//	print_tag(song, MPD_TAG_NAME, "name");
		//	print_tag(song, MPD_TAG_DATE, "date");


			mpd_song_free(song);
		}

	mpd_connection_free(conn);

	return 0;
	}
}
