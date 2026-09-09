"""add_autogenerate_to_weather_id

Revision ID: 04e076000cd7
Revises: 397990d6d402
Create Date: 2026-09-09 20:07:17.230918

"""
from typing import Sequence, Union

from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision: str = '04e076000cd7'
down_revision: Union[str, Sequence[str], None] = '397990d6d402'
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    op.execute('CREATE SEQUENCE weather_forecast_id_seq')
    op.execute(
        'ALTER TABLE weather_forecast '
        'ALTER COLUMN id SET DEFAULT nextval(\'weather_forecast_id_seq\')'
    )    
    op.execute(
        'ALTER SEQUENCE weather_forecast_id_seq '
        'OWNED BY weather_forecast.id'
    )
    op.execute(
        'SELECT setval(\'weather_forecast_id_seq\', '
        'COALESCE((SELECT MAX(id) FROM weather_forecast), 1))'
    )


def downgrade() -> None:
    op.execute(
        'ALTER TABLE weather_forecast '
        'ALTER COLUMN id DROP DEFAULT'
    )    
    op.execute('DROP SEQUENCE weather_forecast_id_seq')
